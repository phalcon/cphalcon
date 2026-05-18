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

namespace Phalcon\Tests\Unit\Forms\Fake;

use Phalcon\Forms\Element\ElementInterface;

final class FakeSentinelElementFactory
{
    public function __construct(
        private readonly ElementInterface $element
    ) {
    }

    public function __invoke(string $name, array $options, array $attributes): ElementInterface
    {
        return $this->element;
    }
}
