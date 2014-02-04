--TEST--
Make Phalcon\Logger compatible with PSR-3
--SKIPIF--
<?php include('skipif.inc'); ?>
--INI--
phalcon.register_psr3_classes = 1
date.timezone = UTC
--FILE--
<?php
$logger = new \Phalcon\Logger\Adapter\Stream("php://stdout");
$logger->log('This is a debug message');
$logger->log('This is a warning message', \Phalcon\Logger::WARNING);

$logger->log('debug', 'This is a debug message');
$logger->log('warning', 'This is a warning message');
$logger->log(\Phalcon\Logger::ERROR, 'This is an error message');

$logger->info('{Message {nothing} {user} {foo.bar} a}', array('user' => 'Bob', 'foo.bar' => 'Bar'));

assert(interface_exists('Psr\Log\LoggerAwareInterface', false));
assert(interface_exists('Psr\Log\LoggerInterface', false));

assert(class_exists('Psr\Log\AbstractLogger', false));
assert(class_exists('Psr\Log\InvalidArgumentException', false));
assert(class_exists('Psr\Log\LogLevel', false));
assert(class_exists('Psr\Log\NullLogger', false));

if (PHP_VERSION_ID >= 50400) {
	assert(trait_exists('Psr\Log\LoggerAwareTrait', false));
	assert(trait_exists('Psr\Log\LoggerTrait', false));
}

?>
--EXPECTF--
[%s, %d %s %d %d:%d:%d %s][DEBUG] This is a debug message
[%s, %d %s %d %d:%d:%d %s][WARNING] This is a warning message
[%s, %d %s %d %d:%d:%d %s][DEBUG] This is a debug message
[%s, %d %s %d %d:%d:%d %s][WARNING] This is a warning message
[%s, %d %s %d %d:%d:%d %s][ERROR] This is an error message
[%s, %d %s %d %d:%d:%d %s][INFO] {Message {nothing} Bob Bar a}
