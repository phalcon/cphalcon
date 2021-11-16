<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Translate\Adapter\Csv;

use ArrayAccess;
use Codeception\Stub;
use Phalcon\Tests\Fixtures\Traits\TranslateCsvTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

use function dataDir;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Csv
 */
class ConstructCest
{
    use TranslateCsvTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvConstruct(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - constructor');

        $language   = $this->getCsvConfig()['en'];
        $translator = new Csv(new InterpolatorFactory(), $language);

        $I->assertInstanceOf(ArrayAccess::class, $translator);
        $I->assertInstanceOf(AdapterInterface::class, $translator);
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: __construct() - Exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvContentParamExist(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - constructor without content throws exception');

        $I->expectThrowable(
            new Exception("Parameter 'content' is required"),
            function () {
                new Csv(new InterpolatorFactory(), []);
            }
        );
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: __construct() - Exception error loading file
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvErrorLoadingFile(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - constructor error loading file throws exception');

        $message = "Error opening translation file '"
            . dataDir('assets/translation/csv/en.csv') . "'";
        $I->expectThrowable(
            new Exception($message),
            function () {
                $language   = $this->getCsvConfig()['en'];
                $translator = Stub::construct(
                    Csv::class,
                    [
                        new InterpolatorFactory(),
                        $language,
                    ],
                    [
                        'phpFopen' => false,
                    ]
                );
            }
        );
    }
}
