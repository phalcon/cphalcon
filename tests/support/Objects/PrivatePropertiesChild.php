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

namespace Phalcon\Tests\Support\Objects;

/**
 * Fixture for Hydration\GetPrivateProperties: redeclares `shadowed` so the
 * child-wins rule can be asserted.
 */
class PrivatePropertiesChild extends PrivatePropertiesParent
{
    private $childOnly = null;

    private $shadowed = 'child';
}
