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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class InitCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: init()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesInit(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - init()');

        $attributes = new Attributes();

        $expected = [
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes->init($expected);

        $actual = $attributes->toArray();

        $I->assertSame($expected, $actual);
    }
}
