<?php
/**
 * TestsBase.php
 * \Phalcon\_Helper\TestsBase
 *
 * Base class for all tests
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

namespace Phalcon\Tests\unit\Phalcon\_Helper;

use \Phalcon\DI as PhDI;
use \Phalcon\DI\FactoryDefault as PhDIFD;
use \PhalconTest\Mvc\Url as PhTUrl;
use \PhalconTest\Escaper as PhTEscaper;

use \Codeception\TestCase\Test as CdTest;
use \Codeception\Specify as CdSpecify;

class TestsBase extends CdTest
{
    use CdSpecify;

    /**
     * Sets up the DI
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     *
     * @param bool $static
     *
     * @return \Phalcon\DI\FactoryDefault
     */
    protected function prepareDI($static = false)
    {
        PhDI::reset();

        $di = new PhDIFD();

        $this->prepareUrl($di, $static);
        $this->prepareEscaper($di);

        return $di;
    }

    /**
     * Prepares the url service for the di
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2013-10-30
     *
     * @param $di
     */
    protected function prepareUrl($di, $static = false)
    {
        $di->set(
            'url',
            function () use ($static) {
                $url = new PhTUrl();
                if ($static) {
                    $url->setStaticBaseUri('/');
                } else {
                    $url->setBaseUri('/');
                }
                return $url;
            }
        );
    }

    /**
     * Prepares the escaper service for the di
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2013-10-30
     *
     * @param $di
     */
    protected function prepareEscaper($di)
    {
        $di->set(
            'escaper',
            function () {
                return new PhTEscaper();
            }
        );
    }
}
