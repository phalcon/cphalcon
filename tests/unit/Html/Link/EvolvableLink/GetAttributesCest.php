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

namespace Phalcon\Tests\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: getAttributes()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkGetAttributes(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - getAttributes()');

        $href       = 'https://dev.phalcon.ld';
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
