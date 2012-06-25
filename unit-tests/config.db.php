<?php

$configMysql = new stdClass();
$configMysql->adapter = 'Mysql';
$configMysql->host = '127.0.0.1';
$configMysql->username = 'root';
$configMysql->password = '';
$configMysql->name = 'phalcon_test';

$configPostgresql = new stdClass();
$configPostgresql->adapter = 'Postgresql';
$configPostgresql->host = '127.0.0.1';
$configPostgresql->username = 'postgres';
$configPostgresql->password = '';
$configPostgresql->name = 'phalcon_test';
