--TEST--
Make Phalcon\Logger compatible with PSR-3
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$logger = new \Phalcon\Logger\Adapter\Stream("php://stdout");
$logger->log('This is a debug message');
$logger->log('This is a warning message', \Phalcon\Logger::WARNING);

$logger->log('debug', 'This is a debug message');
$logger->log('warning', 'This is a warning message');
$logger->log(\Phalcon\Logger::ERROR, 'This is an error message');

$logger->info('{Message {nothing} {user} {foo.bar} a}', array('user' => 'Bob', 'foo.bar' => 'Bar'));
?>
--EXPECTF--
[%s, %d %s %d %d:%d:%d %s][DEBUG] This is a debug message
[%s, %d %s %d %d:%d:%d %s][WARNING] This is a warning message
[%s, %d %s %d %d:%d:%d %s][DEBUG] This is a debug message
[%s, %d %s %d %d:%d:%d %s][WARNING] This is a warning message
[%s, %d %s %d %d:%d:%d %s][ERROR] This is an error message
[%s, %d %s %d %d:%d:%d %s][INFO] {Message {nothing} Bob Bar a}
