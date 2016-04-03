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

	public function testDefaults()
	{
		$s = new \Phalcon\Security;
		$this->assertEquals(null, $s->getDefaultHash());
		$this->assertEquals(16, $s->getRandomBytes());
	}

	public function testSelf()
	{
		$s = new \Phalcon\Security;
		$this->assertEquals($s, $s->setRandomBytes(22));
		$this->assertEquals($s, $s->setDefaultHash('some_hash_value'));

		$this->assertEquals(22, $s->getRandomBytes());
		$this->assertEquals('some_hash_value', $s->getDefaultHash());
	}

	public function testTokenOnePerRequest()
	{
		$s = $this->getDI()->get('security');	

		$tokenKey = $s->getTokenKey();
		$token = $s->getToken();		

		$this->assertNotEmpty($tokenKey);
		$this->assertNotEmpty($token);

		$this->assertEquals($tokenKey, $s->getTokenKey());
		$this->assertEquals($token, $s->getToken());
		$this->assertEquals($token, $s->getSessionToken());

		$s->destroyToken();

		$this->assertNotEquals($tokenKey, $s->getTokenKey());
		$this->assertNotEquals($token, $s->getToken());
		$this->assertNotEquals($token, $s->getSessionToken());	

		$s->destroyToken();	
	}

	public function testCheckToken()
	{
		$s = $this->getDI()->get('security');	

		// Random token and token key check
		$tokenKey = $s->getTokenKey();
		$token = $s->getToken();

		$_POST = array($tokenKey => $token);

		$this->assertTrue($s->checkToken(null, null, false));
		$this->assertTrue($s->checkToken());
		$this->assertFalse($s->checkToken());

		// Destroy token check
		$tokenKey = $s->getTokenKey();
		$token = $s->getToken();

		$s->destroyToken();

		$_POST = array($tokenKey => $token);

		$this->assertFalse($s->checkToken());

		// Custom token key check
		$token = $s->getToken();

		$_POST = array('custom_key' => $token);

		$this->assertFalse($s->checkToken(null, null, false));
		$this->assertFalse($s->checkToken('other_custom_key', null, false));
		$this->assertTrue($s->checkToken('custom_key'));

		// Custom token value check
		$token = $s->getToken();

		$_POST = array();

		$this->assertFalse($s->checkToken(null, null, false));
		$this->assertFalse($s->checkToken('some_random_key', 'some_random_value', false));
		$this->assertTrue($s->checkToken('custom_key', $token));
	}

	public function testGetSaltBytes()
	{
		$s = new \Phalcon\Security;

		$salt = $s->getSaltBytes(22);

		$this->assertNotEmpty($salt);
		$this->assertTrue(strlen($salt) > 22);		
	}

	protected function getDI()
	{
		$di = new Phalcon\DI\FactoryDefault();
		@session_start();

		return $di;	
	}
}
