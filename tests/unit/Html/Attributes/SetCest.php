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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Html\Attributes :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - set()');

        $attributes = new Attributes();

        $attributes->set('class', 'form-control');

        $I->assertEquals(
            'form-control',
            $attributes->get('class')
        );
    }
}
