<?php
/**
 * UnitTest.php
 * Security_UnitTest
 *
 * Tests the \Phalcon\Filter component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Security;

class UnitTest extends \Phalcon\Test\UnitTestCase
{
	/**
	 * Tests the hash for the security component
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-03-02
	 * @requires extension openssl
	 */
	public function testHash()
	{
		$security = new \Phalcon\Security();

		for ($i = 8; $i < 12; $i++) {
			$hash = $security->hash('a', $i);
			$this->assertTrue($security->checkHash('a', $hash));
		}

		for ($i = 8; $i < 12; $i++) {
			$hash = $security->hash('aaaaaaaaaaaaaa', $i);
			$this->assertTrue($security->checkHash('aaaaaaaaaaaaaa', $hash));
		}
	}

	/**
	 * Tests \Phalcon\Security::computeHmac()
	 *
	 * @author Vladimir Kolesnikov <vladimir@extrememember.com>
	 * @since 2013-10-08
	 * @requires function hash_hmac
	 */
	public function testComputeHMAC()
	{
		$s = new \Phalcon\Security();
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
