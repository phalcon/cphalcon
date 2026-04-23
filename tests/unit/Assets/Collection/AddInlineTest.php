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

namespace Phalcon\Tests\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use Phalcon\Assets\Inline;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class AddInlineTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsCollectionAddInline(): void
    {
        $collection = new Collection();
        $inline     = new Inline('js', "alert('an amazing test');");
        $collection->addInline($inline);

        $codes = $collection->getCodes();

        $this->assertCount(1, $collection->getCodes());
        $this->assertSame(end($codes), $inline);
    }
}
