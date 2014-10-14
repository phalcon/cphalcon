<?php
/**
 * AssetsBase.php
 * \Phalcon\Resource\Helper\AssetsBase
 *
 * Base class for Assets tests
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

namespace Phalcon\Tests\unit\Phalcon\Assets\Helper;

use \Phalcon\DI as PhDI;
use \PhalconTest\Mvc\Url as PhTUrl;
use \PhalconTest\Escaper as PhTEscaper;

use \Codeception\TestCase\Test as CdTest;

class AssetsBase extends CdTest
{
    use \Codeception\Specify;

    /**
     * Sets up the DI and the escaper
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     *
     * @param bool $static
     */
    protected function prepareDI($static = false)
    {
        PhDI::reset();

        $di = new PhDI();

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

        $di->set(
            'escaper',
            function() {
                return new PhTEscaper();
            }
        );
    }
}
