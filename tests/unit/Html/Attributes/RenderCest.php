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

namespace Phalcon\Tests\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class RenderCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Html\Attributes :: render()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function htmlAttributesRender(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - render()');

        $attributes = new Attributes(
            [
                'type'  => 'text',
                'class' => 'form-control',
                'name'  => 'q',
                'value' => '',
            ]
        );

        $expected = 'type="text" name="q" value="" class="form-control" ';
        $actual   = $attributes->render();
        $I->assertSame($expected, $actual);
    }
}
