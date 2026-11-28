<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di\Service;

use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

use function spl_object_id;

final class SetSharedInstanceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceSetSharedInstance(): void
    {
        $escaper = new Escaper();
        $service = new Service($escaper, true);
        $service->setSharedInstance($escaper);

        $expected = spl_object_id($escaper);
        $actual   = spl_object_id($service->resolve());
        $this->assertSame($expected, $actual);
    }
}
