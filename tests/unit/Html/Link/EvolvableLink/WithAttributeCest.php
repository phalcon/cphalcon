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

namespace Phalcon\Test\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

class WithAttributeCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: withAttribute()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkWithAttribute(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - withAttribute()');

        $href       = 'https://dev.phalcon.ld';
        $attributes = ['one' => true];

        $link = new EvolvableLink('payment', $href, $attributes);

        $newInstance = $link->withAttribute('two', 'three');

        $I->assertNotSame($link, $newInstance);

        $expected = [
            'one' => true,
            'two' => 'three',
        ];

        $I->assertEquals($expected, $newInstance->getAttributes());
    }
}
