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

class OffsetGetCest
{
    use TranslateCsvTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: offsetGet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterCsvOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - offsetGet()');

        $language = $this->getCsvConfig()['en'];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        $I->assertEquals(
            'Hello',
            $translator->offsetGet('hi')
        );
    }
}
