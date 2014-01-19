--TEST--
Phalcon\Logger\Adapter::commit() does not clear the queue - https://github.com/phalcon/cphalcon/issues/1742
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class MyStreamAdapter extends \Phalcon\Logger\Adapter\Stream
{
	public function getQueueSize()
	{
		return count($this->_queue);
	}
}

$logger = new MyStreamAdapter("php://stdout");
$logger->begin();
$logger->log('info', \Phalcon\Logger::INFO);
$logger->log('critical', \Phalcon\Logger::CRITICAL);
echo $logger->getQueueSize(), PHP_EOL;
$logger->commit();
echo $logger->getQueueSize(), PHP_EOL;
?>
--EXPECTF--
2
[%s, %d %s %d %d:%d:%d %s][INFO] info
[%s, %d %s %d %d:%d:%d %s][CRITICAL] critical
0
