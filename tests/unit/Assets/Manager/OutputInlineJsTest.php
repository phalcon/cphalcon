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

use const PHP_EOL;

final class OutputInlineJsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAssetsManagerOutputInlineJs(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $js      = 'alert("Hello world");';

        $manager->addInlineJs($js);
        $manager->useImplicitOutput(false);

        $expected = "<script type=\"application/javascript\">{$js}</script>" . PHP_EOL;
        $actual   = $manager->outputInlineJs();
        $this->assertSame($expected, $actual);
    }
}
