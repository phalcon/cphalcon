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

namespace Phalcon\Tests\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineCssConstruct(): void
    {
        $asset = new Css('p {color: #000099}');

        $expected = 'css';
        $actual   = $asset->getType();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineCssConstructAttributes(): void
    {
        $asset = new Css('p {color: #000099}');

        $expected = [
            'type' => 'text/css',
        ];
        $actual   = $asset->getAttributes();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineCssConstructAttributesSet(): void
    {
        $attributes = [
            'data' => 'phalcon',
        ];

        $asset  = new Css(
            'p {color: #000099}',
            true,
            $attributes
        );
        $actual = $asset->getAttributes();
        $this->assertSame($attributes, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineCssConstructFilter(): void
    {
        $asset  = new Css('p {color: #000099}');
        $actual = $asset->getFilter();
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineCssConstructFilterSet(): void
    {
        $asset  = new Css('p {color: #000099}', false);
        $actual = $asset->getFilter();
        $this->assertFalse($actual);
    }
}
