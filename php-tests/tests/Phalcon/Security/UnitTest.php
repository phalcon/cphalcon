<?php
/**
 * UnitTest.php
 * Security_UnitTest
 *
 * Tests the \Phalcon\Filter component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2013 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Security as Security;

class Security_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the hash for the security component
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2013-03-02
     */
    public function testHash()
    {

        if (!extension_loaded('openssl')) {
            $this->markTestSkipped('Warning: openssl extension is not loaded');
            return;
        }

        $security = new Security();

        for ($i = 8; $i < 12; $i++) {
            $hash = $security->hash('a', $i);
            $this->assertTrue($security->checkHash('a', $hash));
        }

        for ($i = 8; $i < 12; $i++) {
            $hash = $security->hash('aaaaaaaaaaaaaa', $i);
            $this->assertTrue($security->checkHash('aaaaaaaaaaaaaa', $hash));
        }
    }
}

