<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\EvolvableLink;

use Phalcon\Link\EvolvableLink;
use UnitTester;

class WithAttributeCest
{
    /**
     * Tests Phalcon\Link\Link :: withAttribute()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkWithAttribute(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLink - withAttribute()');

        $href       = 'https://dev.cardoe.ld';
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
