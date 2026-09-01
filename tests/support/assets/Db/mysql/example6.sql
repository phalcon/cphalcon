CREATE TABLE `table` (
	`id_user` BIGINT(20) UNSIGNED,
	CONSTRAINT `fk_id_user` FOREIGN KEY (`id_user`) REFERENCES `database2`.`users` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
)
