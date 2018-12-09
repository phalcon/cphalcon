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

use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\Csv;
use UnitTester;

class ExistsCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: exists()
     *
     * @param UnitTester $I
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function translateAdapterCsvExists(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Csv - exists()');
        $params     = $this->getCsvConfig()['ru'];
        $translator = new Csv($params);

        $actual = $translator->exists('Hi!');
        $I->assertFalse($actual);

        $actual = $translator->exists('Hello!');
        $I->assertTrue($actual);
    }
}
