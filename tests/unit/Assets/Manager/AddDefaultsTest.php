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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function array_values;
use function end;

final class AddDefaultsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsManagerAddCssDefaults(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->addCss('/css/style.css');

        $asset = array_values($manager->get('css')->getAssets())[0];

        $this->assertTrue($asset->getFilter());
        $this->assertFalse($asset->isAutoVersion());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsManagerAddInlineCssDefaults(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->addInlineCss('.example {}');

        $codes = $manager->get('css')->getCodes();
        $code  = end($codes);

        $this->assertTrue($code->getFilter());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsManagerAddInlineJsDefaults(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->addInlineJs('var example;');

        $codes = $manager->get('js')->getCodes();
        $code  = end($codes);

        $this->assertTrue($code->getFilter());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsManagerAddJsDefaults(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->addJs('/js/script.js');

        $asset = array_values($manager->get('js')->getAssets())[0];

        $this->assertTrue($asset->getFilter());
        $this->assertFalse($asset->isAutoVersion());
    }
}
