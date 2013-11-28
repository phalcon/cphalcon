--TEST--
Memory corruption in zim_Phalcon_Security_hash() - https://github.com/phalcon/cphalcon/issues/1340 - run under Valgrind!
--SKIPIF--
<?php
include('skipif.inc');
if (!extension_loaded('openssl')) {
	die('skip OpenSSL extension is not loaded');
}
?>
--FILE--
<?php
$s = new \Phalcon\Security();
$s->setWorkFactor(10);
$hash = $s->hash('password', null);
echo "OK", PHP_EOL;

try {
	$s = new \Phalcon\Db\Adapter\Pdo\Mysql(array());
	$s->connect(null);
}
catch (Exception $e) {
}
echo "OK", PHP_EOL;

try {
	$s = new \Phalcon\Db\Adapter\Pdo\Oracle(array('username' => 'oracle', 'password' => 'oracle'));
	$s->connect(null);
}
catch (Exception $e) {
}
echo "OK", PHP_EOL;

try {
	$s = new \Phalcon\Db\Adapter\Pdo\Postgresql(array('username' => 'postgresql', 'password' => ''));
	$s->connect(null);
}
catch (Exception $e) {
}
echo "OK", PHP_EOL;

try {
	$s = new \Phalcon\Db\Adapter\Pdo\Sqlite(array('dbname' => __DIR__ . '/test.sqlite'));
	$s->connect(null);
}
catch (Exception $e) {
	echo $e->getMessage();
}
echo "OK", PHP_EOL;

?>
--EXPECT--
OK
OK
OK
OK
OK
--CLEAN--
<?php @unlink(__DIR__ . '/test.sqlite'); ?>
