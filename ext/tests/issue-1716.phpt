--TEST--
Phalcon\Logger\Adapter::setLogLevel() is not working properly - https://github.com/phalcon/cphalcon/issues/1716
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$logger = new \Phalcon\Logger\Adapter\Stream("php://stdout");
$logger->setLogLevel(\Phalcon\Logger::CRITICAL);
$logger->begin();
$logger->log('info', \Phalcon\Logger::INFO);
$logger->log('critical', \Phalcon\Logger::CRITICAL);
$logger->commit();
?>
--EXPECTF--
[%s, %d %s %d %d:%d:%d %s][CRITICAL] critical
