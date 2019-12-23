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

class GetAttributesCest
{
    /**
     * Tests Phalcon\Link\Link :: getAttributes()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkGetAttributes(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLink - getAttributes()');

        $href       = 'https://dev.cardoe.ld';
        $attributes = [
            'one'   => true,
            'two'   => 123,
            'three' => 'four',
            'five'  => [
                'six',
                'seven',
            ],
        ];
        $link       = new EvolvableLink('payment', $href, $attributes);

        $I->assertEquals($attributes, $link->getAttributes());
    }
}
