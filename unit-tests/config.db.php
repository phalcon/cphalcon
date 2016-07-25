<?php

if (!file_exists(__DIR__ . '/config.db.local.php')) {

	$configMysql = array(
		'host' => 'localhost',
		'username' => 'root',
		'password' => '',
		'dbname' => 'phalcon_test'
	);

	// Skipped in view of the experimental support for PHP 7.
	//if (PHP_MAJOR_VERSION != 7) {
		$configPostgresql = array(
			'host' => '127.0.0.1',
			'username' => 'postgres',
			'password' => '',
			'dbname' => 'phalcon_test',
			'schema' => 'public'
		);
	//}

	$configSqlite = array(
		'dbname' => '/tmp/phalcon_test.sqlite',
	);
}
else {
	require __DIR__ . '/config.db.local.php';
}
