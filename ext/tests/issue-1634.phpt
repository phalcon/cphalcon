--TEST--
Safe unserialization of Phalcon\Queue\Beanstalk\Job - https://github.com/phalcon/cphalcon/pull/1634
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class Test extends \Phalcon\Queue\Beanstalk\Job
{
	public function setId($id)
	{
		$this->_id = $id;
	}

	public function setQueue($queue)
	{
		$this->_queue = $queue;
	}
}

try {
	$j = new \Test(null, 'id', 'body');
	assert(false);
}
catch (\Phalcon\Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

/*
$j = new \Test(new \Phalcon\Queue\Beanstalk(), 'id', 'body');
$j->setQueue(new stdClass);
echo base64_encode(serialize($j)), PHP_EOL;
*/

// O:4:"Test":3:{s:9:"*_queue";O:23:"Phalcon\Queue\Beanstalk":2:{s:14:"*_connection";N;s:14:"*_parameters";a:2:{s:4:"host";s:9:"127.0.0.1";s:4:"port";i:11300;}}s:6:"*_id";a:0:{}s:8:"*_body";s:4:"body";}
$s = base64_decode('Tzo0OiJUZXN0IjozOntzOjk6IgAqAF9xdWV1ZSI7TzoyMzoiUGhhbGNvblxRdWV1ZVxCZWFuc3RhbGsiOjI6e3M6MTQ6IgAqAF9jb25uZWN0aW9uIjtOO3M6MTQ6IgAqAF9wYXJhbWV0ZXJzIjthOjI6e3M6NDoiaG9zdCI7czo5OiIxMjcuMC4wLjEiO3M6NDoicG9ydCI7aToxMTMwMDt9fXM6NjoiACoAX2lkIjthOjA6e31zOjg6IgAqAF9ib2R5IjtzOjQ6ImJvZHkiO30=');
try {
	unserialize($s);
}
catch (\Phalcon\Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

// O:4:"Test":3:{s:9:"*_queue";O:8:"stdClass":0:{}s:6:"*_id";s:2:"id";s:8:"*_body";s:4:"body";}
$s = base64_decode('Tzo0OiJUZXN0IjozOntzOjk6IgAqAF9xdWV1ZSI7Tzo4OiJzdGRDbGFzcyI6MDp7fXM6NjoiACoAX2lkIjtzOjI6ImlkIjtzOjg6IgAqAF9ib2R5IjtzOjQ6ImJvZHkiO30=');
try {
	unserialize($s);
}
catch (\Phalcon\Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

?>
--EXPECT--
Unexpected value type: expected object of type Phalcon\Queue\Beanstalk, null given
Unexpected inconsistency in Phalcon\Queue\Beanstalk\Job::__wakeup() - possible break-in attempt!
Unexpected value type: expected object of type Phalcon\Queue\Beanstalk, object of type stdClass given
