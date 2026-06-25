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

use function array_values;
use function end;

final class AddDefaultsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsCollectionAddCssDefaults(): void
    {
        $collection = new Collection();
        $collection->addCss('css/docs.css');

        $asset = array_values($collection->getAssets())[0];

        // filter defaults to true, autoVersion defaults to false
        $this->assertTrue($asset->getFilter());
        $this->assertFalse($asset->isAutoVersion());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsCollectionAddInlineCssDefaults(): void
    {
        $collection = new Collection();
        $collection->addInlineCss('.example {}');

        $codes = $collection->getCodes();
        $code  = end($codes);

        $this->assertTrue($code->getFilter());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsCollectionAddInlineJsDefaults(): void
    {
        $collection = new Collection();
        $collection->addInlineJs('var example;');

        $codes = $collection->getCodes();
        $code  = end($codes);

        $this->assertTrue($code->getFilter());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsCollectionAddJsDefaults(): void
    {
        $collection = new Collection();
        $collection->addJs('js/jquery.js');

        $asset = array_values($collection->getAssets())[0];

        // filter defaults to true, autoVersion defaults to false
        $this->assertTrue($asset->getFilter());
        $this->assertFalse($asset->isAutoVersion());
    }
}
