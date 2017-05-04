<hr/>
<?php
// galerie
$max = 5;
$totalDesMessages = Images::stat_img();
$nombreDePages  = ceil($totalDesMessages / $max);

echo 'Page : ';
for ($i = 1 ; $i <= $nombreDePages ; $i++)
    echo '<a href="index.php?pg=7&ga=' . $i . '">' . $i . '</a> ';
?>
<hr/>
<?php
if (check($_GET['ga']))
        $page = securiter($_GET['ga']);
else
    $page = 1;

$min = ($page - 1) * $max;

$donnee = Images::aff_galerie($min, $max);
$id = 0;
if (check($er_com))
    echo "<p class='erreur'>".$er_com."</p>";
while ($donnee[$id])
{
    $img_usr = Membre::info_usr($donnee[$id]['user_id']);
    ?>
    <div id='ga_img'>
        <img class="img_ga" src='<?= $donnee[$id]['image']; ?>' />
    </div>
    <div id="ga_descrip">
        <?php
            if ($_SESSION['user']['id'] == $donnee[$id]['user_id']) {
                ?>
                <form action="index.php?pg=7&ga=<?= $page; ?>&id=<?= $donnee[$id]['id'] ?>&sp=co" method="POST">
                    <input type="submit" name="sup" value="Supprimer cette photos"/>
                </form>
                <?php
            }
        ?>
        Par <?= $img_usr['login']; ?><br/>
        Le <?= $donnee[$id]['time']; ?><br/>
        <?= Comment::nbr_like($donnee[$id]['id']); ?> like.
        <hr/>
        <?php
        if (check($_SESSION['user']['id'])) {
        ?>
        <form action="index.php?pg=7&ga=<?= $page; ?>&id=<?= $donnee[$id]['id'] ?>" method="POST">
            <textarea row="51" cols="10" name="texte"></textarea><br/>
            <input name="com" type="submit" value="Commenter" />
        </form>
        <form action="index.php?pg=7&ga=<?= $page; ?>&id=<?= $donnee[$id]['id'] ?>" method="POST">
            <?php
                // verrif si like ou dislike
                if (!(Comment::text_like($donnee[$id]['id'], $_SESSION['user']['id'])))
                    echo '<input name="like" type="submit" value="like" />';
                else
                    echo '<input name="like" type="submit" value="dislike" />';
            ?>
        </form>
        <?php
        }
        else
            echo "Vous devez être connecter pour commenter ou liker.";
        ?>
        <hr/>
        <?php
        $id_com = 0;
        $comm = Comment::aff_com($donnee[$id]['id']);
        while ($comm[$id_com]) {
            echo $comm[$id_com]['texte']."<br/><br/>";
            $id_com++;
        }
        ?>
        <hr/>
    </div>
    <?php
    $id++;
}
?>