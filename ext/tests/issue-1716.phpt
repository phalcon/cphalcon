--TEST--
Phalcon\Logger\Adapter::setLogLevel() is not working properly - https://github.com/phalcon/cphalcon/issues/1716
--SKIPIF--
<?php include('skipif.inc'); ?>
--INI--
date.timezone=UTC
--FILE--
<?php
$logger = new \Phalcon\Logger\Adapter\Stream("php://stdout");
$logger->setLogLevel(\Phalcon\Logger::CRITICAL);
$logger->begin();
$logger->log(\Phalcon\Logger::INFO, 'info');
$logger->log(\Phalcon\Logger::CRITICAL, 'critical');
$logger->commit();
?>
--EXPECTF--
[%s, %d %s %d %d:%d:%d %s][CRITICAL] critical
