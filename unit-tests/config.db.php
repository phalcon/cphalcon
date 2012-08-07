<?php

$configMysql = new stdClass();
$configMysql->adapter = 'mysql';
$configMysql->dsn = 'host=127.0.0.1;dbname=phalcon_test';
$configMysql->username = 'root';
$configMysql->password = '';

$configPostgresql = new stdClass();
$configPostgresql->adapter = 'postgresql';
$configPostgresql->dsn = 'host=127.0.0.1;dbname=phalcon_test';
$configPostgresql->username = 'postgres';
$configPostgresql->password = '';
