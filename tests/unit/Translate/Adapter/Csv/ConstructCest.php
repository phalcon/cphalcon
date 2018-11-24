<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter\Csv;

use ArrayAccess;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\AdapterInterface;
use Phalcon\Translate\Exception;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Translate\Adapter\Csv :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterCsvConstruct(UnitTester $I)
    {
        $params     = ['content' => PATH_DATA . 'assets/translation/csv/ru_RU.csv'];
        $translator = new Csv($params);

        $class = ArrayAccess::class;
        $I->assertInstanceOf($class, $translator);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $translator);
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: __construct() - Exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterCsvContentParamExist(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception("Parameter 'content' is required"),
            function () {
                new Csv([]);
            }
        );
    }
}
