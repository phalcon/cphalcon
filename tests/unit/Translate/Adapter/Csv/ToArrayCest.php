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

class ToArrayCest
{
    use TranslateCsvTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: toArray()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvToArray(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - toArray()');

        $language   = $this->getCsvConfig()['en'];
        $translator = new Csv(new InterpolatorFactory(), $language);

        $expected = [
            'hi'        => 'Hello',
            'bye'       => 'Good Bye',
            'hello-key' => 'Hello %name%',
            'song-key'  => 'This song is %song% (%artist%)',
        ];
        $actual   = $translator->toArray();
        $I->assertSame($expected, $actual);
    }
}
