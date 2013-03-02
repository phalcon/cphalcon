<?php

namespace Dynamic;

/**
 * Personers
 *
 * Personers is people in danish
 */
class Personers extends \Phalcon\Mvc\Model
{

	public function columnMap()
	{
		return array(
			'cedula' => 'borgerId',
			'tipo_documento_id' => 'slagBorgerId',
			'nombres' => 'navnes',
			'telefono' => 'telefon',
			'direccion' => 'adresse',
			'email' => 'elektroniskPost',
			'fecha_nacimiento' => 'fodtDato',
			'ciudad_id' => 'fodebyId',
			'creado_at' => 'skabtPa',
			'cupo' => 'kredit',
			'estado' => 'status'
		);
	}

	public function initialize()
	{
		$this->setSource('personas');
		$this->useDynamicUpdate(true);
	}

}