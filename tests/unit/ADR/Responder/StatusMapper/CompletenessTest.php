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

namespace Phalcon\Tests\Unit\ADR\Responder\StatusMapper;

use Phalcon\ADR\Payload\Status;
use Phalcon\ADR\Responder\StatusMapper;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionClass;
use ReflectionProperty;

final class CompletenessTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\StatusMapper :: every Status is mapped
     */
    public function testAdrResponderStatusMapperMapsEveryStatus(): void
    {
        $mapper = new StatusMapper();

        $property = new ReflectionProperty($mapper, 'map');
        $property->setAccessible(true);
        $map = $property->getValue($mapper);

        $statuses = (new ReflectionClass(Status::class))->getConstants();

        foreach ($statuses as $status) {
            $this->assertArrayHasKey(
                $status,
                $map,
                "Status '" . $status . "' has no HTTP code mapping"
            );
        }
    }
}
