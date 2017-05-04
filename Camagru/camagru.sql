-- phpMyAdmin SQL Dump
-- version 4.5.0.2
-- http://www.phpmyadmin.net
--
-- Host: 172.17.0.2:3306
-- Generation Time: May 09, 2016 at 01:16 PM
-- Server version: 5.5.49
-- PHP Version: 5.6.9-1+deb.sury.org~trusty+2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `camagru`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `id` int(11) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `message` varchar(255) NOT NULL,
  `priorite` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `time`, `message`, `priorite`) VALUES
(1, '2016-05-08 18:22:18', 'L''utilisateur (1) a ajouter une image Ã  sa galerie.', 2),
(2, '2016-05-08 18:22:22', 'L''utilisateur (1) a ajouter une image Ã  sa galerie.', 2),
(3, '2016-05-08 18:28:14', 'L''utilisateur (1) a ajouter une image Ã  sa galerie.', 2),
(4, '2016-05-08 18:28:17', 'L''utilisateur (1) a ajouter une image Ã  sa galerie.', 2),
(5, '2016-05-08 18:29:20', 'L''utilisateur (1) a ajouter une image Ã  sa galerie.', 2),
(6, '2016-05-08 18:29:27', 'L''utilisateur (1) a ajouter une image Ã  sa galerie.', 2),
(7, '2016-05-08 19:16:29', 'L''utilisateur (2) a ajouter une image Ã  sa galerie.', 2),
(8, '2016-05-08 19:16:30', 'L''utilisateur (2) a ajouter une image Ã  sa galerie.', 2),
(9, '2016-05-08 19:16:46', 'L''utilisateur (2) a ajouter une image Ã  sa galerie.', 2),
(10, '2016-05-09 13:15:54', 'L''utilisateur (2) a ajouter une image Ã  sa galerie.', 2);

-- --------------------------------------------------------

--
-- Table structure for table `images`
--

CREATE TABLE `images` (
  `id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `image` varchar(255) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `images`
--

INSERT INTO `images` (`id`, `user_id`, `image`, `time`) VALUES
(5, 1, '../images/webcam/572f85809c9c5.png', '2016-05-08 18:29:20'),
(6, 1, '../images/webcam/572f8587b4456.png', '2016-05-08 18:29:27'),
(7, 2, '../images/webcam/572f908db526a.png', '2016-05-08 19:16:29'),
(8, 2, '../images/webcam/572f908e4ef8b.png', '2016-05-08 19:16:30'),
(9, 2, '../images/webcam/572f909ee558e.png', '2016-05-08 19:16:46'),
(10, 2, '../images/webcam/57308d89f269c.png', '2016-05-09 13:15:54');

-- --------------------------------------------------------

--
-- Table structure for table `membre`
--

CREATE TABLE `membre` (
  `id` int(11) NOT NULL,
  `login` varchar(50) NOT NULL,
  `passe` varchar(50) NOT NULL,
  `email` varchar(255) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `valide` varchar(15) NOT NULL,
  `rank` int(11) NOT NULL,
  `active` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `membre`
--

INSERT INTO `membre` (`id`, `login`, `passe`, `email`, `time`, `valide`, `rank`, `active`) VALUES
(1, 'Artyroz', '@( ãV¬ÉGüÒ¿¿\0ÎñHJ', 'Artyrozz@gmail.com', '2016-05-07 00:15:36', 'y62jw80e7o', 0, 1),
(2, 'root', '@( ãV¬ÉGüÒ¿¿\0ÎñHJ', 'Artyro2zz@gmail.com', '2016-05-08 14:45:01', '09q71rtwkj', 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `referencement`
--

CREATE TABLE `referencement` (
  `id` int(11) NOT NULL,
  `include` varchar(255) NOT NULL,
  `description` varchar(550) NOT NULL,
  `titre` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `referencement`
--

INSERT INTO `referencement` (`id`, `include`, `description`, `titre`) VALUES
(1, 'home.php', 'page d''accuel', 'Camagru'),
(2, 'inscription.php', 'veuillez vous inscrire', 'Inscription'),
(3, 'validation.php', 'valider votre compte', 'Pages de validation'),
(4, 'oublier.php', 'changer de mots de passe', 'Password Oublier ?!'),
(5, 'deconnexion.php', 'page de deconnexion', 'Deconnexion'),
(6, 'montage.php', 'montage de vos propres photos', 'Montage'),
(7, 'galerie.php', 'Regarder la galerie', '..:: Galerie ::..');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `images`
--
ALTER TABLE `images`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `membre`
--
ALTER TABLE `membre`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `referencement`
--
ALTER TABLE `referencement`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `images`
--
ALTER TABLE `images`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `membre`
--
ALTER TABLE `membre`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `referencement`
--
ALTER TABLE `referencement`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
