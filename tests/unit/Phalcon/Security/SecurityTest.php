<?php
/**
 * SecurityTest.php
 * \Phalcon\Security
 *
 * Tests the \Phalcon\Security component
 *
 * Phalcon Framework
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

namespace Phalcon\Tests\unit\Phalcon\Security;

use \PhalconTest\Security as PhTSecurity;
use \Codeception\TestCase\Test as CdTest;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class SecurityTest extends TBase
{
    public function _before()
    {
        if (!extension_loaded('openssl')) {
            $this->markTestSkipped('Warning: openssl extension is not loaded');
            return;
        }

        parent::_before();
    }

    /**
     * Tests the HMAC computation
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testSecurityComputeHMAC()
    {
        $this->specify(
            "The HMAC computation values are not identical",
            function () {

                $security = new PhTSecurity();
                $key      = md5('test', true);
                $keys     = array(
                    substr($key, 0, strlen($key) / 2),
                    $key,
                    $key . $key
                );

                $data = array();
                for ($i = 1; $i < 256; ++$i) {
                    $data[] = str_repeat('a', $i);
                }

                foreach ($keys as $key) {
                    foreach ($data as $text) {
                        $actual   = $security->computeHmac($text, $key, 'md5');
                        $expected = hash_hmac('md5', $text, $key);

                        expect($actual)->equals($expected);
                    }
                }
            }
        );
    }
}
