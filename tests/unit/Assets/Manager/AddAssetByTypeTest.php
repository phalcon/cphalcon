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

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class AddAssetByTypeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function testAssetsManagerAddAssetByType(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addAssetByType('css', new Css('/css/style1.css'));
        $manager->addAssetByType('css', new Css('/css/style2.css'));


        $collection = $manager->get('css');
        $expected   = 'css';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $this->assertSame($expected, $actual);
        }

        $this->assertCount(2, $collection);
    }
}
