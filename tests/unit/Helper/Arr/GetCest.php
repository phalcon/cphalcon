<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Helper\Arr :: get() - numeric
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-17
     */
    public function helperArrGetNumeric(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - get() - numeric');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $I->assertEquals(
            'Phalcon',
            Arr::get($collection, 1, 'Error')
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: get() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-17
     */
    public function helperArrGetString(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - get() - string');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $I->assertEquals(
            'Framework',
            Arr::get($collection, 'suffix', 'Error')
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: get() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-17
     */
    public function helperArrGetDefault(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - get() - default');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $I->assertEquals(
            'Error',
            Arr::get($collection, 'unknown', 'Error')
        );
    }
}
