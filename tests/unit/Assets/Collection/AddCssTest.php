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
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class AddCssTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsCollectionAddCss(): void
    {
        $collection = new Collection();
        $collection->addCss('css/docs.css');
        $collection->addCss('https://assets.phalcon.io/phalcon/css/core.css');

        $expected = 'css';
        foreach ($collection as $asset) {
            $actual = $asset->getType();
            $this->assertSame($expected, $actual);
        }

        $this->assertCount(2, $collection);
    }
}
