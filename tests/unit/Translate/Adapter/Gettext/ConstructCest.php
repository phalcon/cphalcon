<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use ArrayAccess;
use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Exception;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\AdapterInterface;
use UnitTester;

class ConstructCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstruct(UnitTester $I)
    {
        $params     = $this->getGettextConfig();
        $translator = new Gettext($params);

        $class = ArrayAccess::class;
        $I->assertInstanceOf($class, $translator);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $translator);
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: __construct() - Exception
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testContentParamExist(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception("Parameter 'locale' is required"),
            function () {
                new Gettext([]);
            }
        );
    }
}
