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

use Phalcon\Tests\Fixtures\Traits\TranslateCsvTrait;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

/**
 * Class ArrayAccessCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Csv
 */
class ArrayAccessCest
{
    use TranslateCsvTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: array access
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvWithArrayAccess(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - array access');

        $language = $this->getCsvConfig()['ru'];

        $translator = new Csv(new InterpolatorFactory(), $language);

        $actual = isset($translator['Hello!']);
        $I->assertTrue($actual);

        $actual = isset($translator['Hi there!']);
        $I->assertFalse($actual);
    }
}
