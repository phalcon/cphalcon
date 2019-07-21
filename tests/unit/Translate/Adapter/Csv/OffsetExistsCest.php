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

use Phalcon\Test\Fixtures\Traits\TranslateCsvTrait;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class OffsetExistsCest
{
    use TranslateCsvTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: offsetExists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterCsvOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - offsetExists()');

        $language = $this->getCsvConfig()['en'];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        $I->assertTrue(
            $translator->offsetExists('hi')
        );
    }
}
