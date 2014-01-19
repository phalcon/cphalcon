--TEST--
MySQL dialect: addColumn()/modifyColumn() ignore AUTO_INCREMENT - https://github.com/phalcon/cphalcon/issues/1695
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$column = new \Phalcon\Db\Column('id', array('type' => Phalcon\Db\Column::TYPE_INTEGER, 'autoIncrement' => true, 'notNull' => true));
$mysql  = new Phalcon\Db\Dialect\MySQL();
$sqlite = new Phalcon\Db\Dialect\SQLite();
echo $mysql->addColumn('tbl', '', $column), PHP_EOL;
echo $mysql->modifyColumn('tbl', '', $column), PHP_EOL;
echo $sqlite->addColumn('tbl', '', $column), PHP_EOL;
?>
--EXPECT--
ALTER TABLE `tbl` ADD `id` INT NOT NULL PRIMARY KEY AUTO_INCREMENT
ALTER TABLE `tbl` MODIFY `id` INT NOT NULL AUTO_INCREMENT
ALTER TABLE "tbl" ADD COLUMN "id" INT NOT NULL PRIMARY KEY AUTOINCREMENT
