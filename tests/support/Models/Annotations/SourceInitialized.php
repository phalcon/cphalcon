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

namespace Phalcon\Tests\Support\Models\Annotations;

use Phalcon\Annotations\Models\MetaData\Source;

/**
 * @Source("ignored_records")
 */
#[Source('ignored_records')]
class SourceInitialized extends SourceModel
{
    public function initialize(): void
    {
        $this->setSource('initialized_records');
    }
}
