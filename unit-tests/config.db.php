<?php

$configMysql = new stdClass();
$configMysql->type = 'mysql';
$configMysql->dsn = 'host=127.0.0.1;dbname=phalcon_test';
$configMysql->username = 'root';
$configMysql->password = 'hea101';

$configPostgresql = new stdClass();
$configPostgresql->adapter = 'Postgresql';
$configPostgresql->host = '127.0.0.1';
$configPostgresql->username = 'postgres';
$configPostgresql->password = '';
$configPostgresql->name = 'phalcon_test';
