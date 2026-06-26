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
use Phalcon\Tests\AbstractUnitTestCase;

final class WithoutRelTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLinkEvolvableLinkWithoutRel(): void
    {
        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $this->assertSame(['payment'], $link->getRels());

        $newInstance = $link
            ->withRel('citation')
            ->withRel('canonical')
        ;

        $this->assertNotSame($link, $newInstance);

        $rels = [
            'payment',
            'citation',
            'canonical',
        ];
        $this->assertSame($rels, $newInstance->getRels());

        $newInstance = $newInstance->withoutRel('citation');

        $rels = [
            'payment',
            'canonical',
        ];
        $this->assertSame($rels, $newInstance->getRels());
    }
}
