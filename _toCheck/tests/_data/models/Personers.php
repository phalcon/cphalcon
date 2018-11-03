<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\Personers
 * Personers is people in danish.
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * @property string $borgerId
 * @property int $slagBorgerId
 * @property string $navnes
 * @property string $telefon
 * @property string $adresse
 * @property string $elektroniskPost
 * @property string $fodtDato
 * @property int $fodebyId
 * @property string $skabtPa
 * @property float $kredit
 * @property string $status
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Personers extends Model
{
    public function getSource()
    {
        return 'personas';
    }

    public function columnMap()
    {
        return [
            'cedula'            => 'borgerId',
            'tipo_documento_id' => 'slagBorgerId',
            'nombres'           => 'navnes',
            'telefono'          => 'telefon',
            'direccion'         => 'adresse',
            'email'             => 'elektroniskPost',
            'fecha_nacimiento'  => 'fodtDato',
            'ciudad_id'         => 'fodebyId',
            'creado_at'         => 'skabtPa',
            'cupo'              => 'kredit',
            'estado'            => 'status',
        ];
    }
}
