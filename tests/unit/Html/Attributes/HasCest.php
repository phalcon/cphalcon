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

class HasCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesHas(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - has()');

        $attributes = new Attributes([
            'class' => 'form-control',
        ]);

        // exists attribute
        $actual = $attributes->has('class');

        $I->assertTrue($actual);

        // non exists attribute
        $actual = $attributes->has('id');

        $I->assertFalse($actual);
    }
}
