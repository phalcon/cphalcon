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

class OffsetExistsCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: offsetExists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - offsetExists()');

        $attributes = new Attributes([
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ]);

        $actual = $attributes->offsetExists('name');
        $I->assertTrue($actual);

        $actual = $attributes->offsetExists('non-exists');
        $I->assertFalse($actual);

        $actual = isset($attributes['name']);
        $I->assertTrue($actual);

        $actual = isset($attributes['non-exists']);
        $I->assertFalse($actual);
    }
}
