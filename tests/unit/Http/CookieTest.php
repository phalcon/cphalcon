<?php

namespace Phalcon\Test\Unit\Http;

use Phalcon\Crypt;
use Phalcon\Http\Cookie;
use Phalcon\DI\FactoryDefault;
use Phalcon\Test\Unit\Http\Helper\HttpBase;

/**
 * Phalcon\Test\Unit\Http\CookieTest
 * Tests the Phalcon\Http\Cookie component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CookieTest extends HttpBase
{
    /**
     * Tests Cookie::getValue with using encryption and default crypt algo.
     *
     * @test
     * @issue  11259
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-10-04
     */
    public function shouldDecryptValueByUsingDefaultEncryptionAlgo()
    {
        $this->specify(
            "The cookie value decrypted incorrectly.",
            function () {
                $di = new FactoryDefault();

                $di->set('crypt', function () {
                    $crypt = new Crypt();
                    $crypt->setKey('cryptkeycryptkey');

                    return $crypt;
                });

                $cookie = new Cookie('test-cookie', 'test', time() + 3600);
                $cookie->setDI($di);
                $cookie->useEncryption(true);

                expect($cookie->getValue())->equals('test');
            }
        );
    }
}
