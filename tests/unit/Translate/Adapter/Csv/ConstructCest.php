<?php
declare(strict_types=1);

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

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Translate\Adapter\Csv :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterCsvConstruct(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - constructor');
        $params     = ['content' => dataFolder('assets/translation/csv/ru_RU.csv')];
        $translator = new Csv($params);

        $class = ArrayAccess::class;
        $I->assertInstanceOf($class, $translator);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $translator);
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: __construct() - Exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterCsvContentParamExist(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - constructor without "content" throws exception');
        $I->expectThrowable(
            new Exception("Parameter 'content' is required"),
            function () {
                new Csv([]);
            }
        );
    }
}
