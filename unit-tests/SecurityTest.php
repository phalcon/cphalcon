<?php

class SecurityTest extends PHPUnit_Framework_TestCase
{
	public function testComputeHMAC()
	{
		$s = new \Phalcon\Security;
		$k = md5('test', true);
		$keys = array(
			substr($k, 0, strlen($k)/2),
			$k,
			$k . $k
		);

		$data = array();
		for ($i=1; $i<256; ++$i) {
			$data[] = str_repeat('a', $i);
		}

		foreach ($keys as $key) {
			foreach ($data as $text) {
				$actual   = $s->computeHmac($text, $key, 'md5');
				$expected = hash_hmac('md5', $text, $key);
				$this->assertEquals($expected, $actual);
			}
		}
	}
}
